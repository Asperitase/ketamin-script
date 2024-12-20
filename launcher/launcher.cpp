#include "launcher.hpp"

#include "../window/window.hpp"

#include <cassert>

namespace global {
    c_launcher::c_launcher( int argc, char* argv[] ) noexcept: _argc( argc ), _argv( argv ) {}

    [[nodiscard]] std::unique_ptr<c_launcher> c_launcher::create( int argc, char* argv[] ) noexcept {
        return std::make_unique<c_launcher>( argc, argv );
    }

    c_launcher::~c_launcher() noexcept = default;

    int c_launcher::start() const noexcept {
        shadowcall<BOOL>( "SetPriorityClass", ( HANDLE )-1, HIGH_PRIORITY_CLASS );

        const auto render = render::c_window::create();
        if ( !render ) {
            assert( render && "Failed to create render window." );
            return -1;
        }

        render->create_window_handle();
        render->render_loop();
        return 0;
    }
} // namespace global