#include "mouse.hpp"

#include <cassert>

#include <syscall.hpp>

#pragma comment( lib, "ntdll.lib" )

namespace {
    // Helper function to call IOCTL control for the mouse
    bool call_move( sdk::mouse::input_t handle, sdk::common::mouse_input& input ) {
        constexpr int offset = 0x2a2010;

        IO_STATUS_BLOCK block;
        return NtDeviceIoControlFile( handle, nullptr, nullptr, nullptr, &block, offset, &input, sizeof( sdk::common::mouse_input ), nullptr, 0 ) == 0L;
    }
} // namespace

namespace sdk::mouse {
    c_mouse* c_mouse::instance_ = nullptr;
    status_block c_mouse::status_io;
    std::optional<input_t> c_mouse::input;

    c_mouse::c_mouse() noexcept {
        instance_ = this;
    }

    c_mouse::~c_mouse() noexcept {
        cleanup();
        instance_ = nullptr;
    }

    [[nodiscard]] c_mouse& c_mouse::instance() noexcept {
        if ( !instance_ )
            assert( instance_ && "Instance of c_mouse not initialized." );

        return *instance_;
    }

    bool c_mouse::startup() noexcept {
        for ( const auto& device_name : device_names ) {
            UNICODE_STRING name;
            OBJECT_ATTRIBUTES attr;
            RtlInitUnicodeString( &name, device_name );
            InitializeObjectAttributes( &attr, &name, 0, nullptr, nullptr );

            NTSTATUS status = NtCreateFile( &input.emplace(), GENERIC_WRITE | SYNCHRONIZE, &attr, &status_io, 0, FILE_ATTRIBUTE_NORMAL, 0, 3,
                                            FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT, 0, 0 );

            if ( NT_SUCCESS( status ) ) {
                return true;
            }
        }
        return false;
    }

    void c_mouse::cleanup() noexcept {
        if ( input ) {
            shadowsyscall( "ZwClose", input.value() );
            input.reset();
        }
    }

    void c_mouse::move( sdk::common::mouse_button button, char x, char y, char wheel, char unk_ ) noexcept {
        sdk::common::mouse_input io_buffer( button, x, y, wheel, unk_ );

        call_move( input.value(), io_buffer );
    }
} // namespace sdk::mouse