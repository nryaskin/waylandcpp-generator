# Waylandcpp Generator

## Overview

Generates waylandcpp headers for usage with [waylandcpp](https://github.com/nryaskin/waylandcpp)
Uses cppgen library which is placed in current repository to generate C++ code.

### CPPGEN
CPPGEN doesn't support a lot of C++ language features because it is not aimed to create powerfull code generator.
It supports enough features to allow *wayland-generator* to create waylandcpp headers for interfaces from wayland's xml specification.

## Build

```
cmake -B <BUILD_FOLDER_PATH> -S ./
```

## Usage

In this example it is assumed that wayland config exists in `/usr/share/wayland/wayland.xml`(It is default location in my system)

To see what files are going to be generated use following command:

```
mkdir generated
waylandcpp-generator --dry-run --output ./generated --config /usr/share/wayland/wayland.xml
```

File `generated/files.cmake` is created(TODO: Change files.cmake from this to files list) 

```
$ cat generated/files.cmake 
set(GENERATED_HEADERS include/waylandcpp/wl_display.hpp
include/waylandcpp/wl_registry.hpp
include/waylandcpp/wl_callback.hpp
include/waylandcpp/wl_compositor.hpp
include/waylandcpp/wl_shm_pool.hpp
include/waylandcpp/wl_shm.hpp
include/waylandcpp/wl_buffer.hpp
include/waylandcpp/wl_data_offer.hpp
include/waylandcpp/wl_data_source.hpp
include/waylandcpp/wl_data_device.hpp
include/waylandcpp/wl_data_device_manager.hpp
include/waylandcpp/wl_shell.hpp
include/waylandcpp/wl_shell_surface.hpp
include/waylandcpp/wl_surface.hpp
include/waylandcpp/wl_seat.hpp
include/waylandcpp/wl_pointer.hpp
include/waylandcpp/wl_keyboard.hpp
include/waylandcpp/wl_touch.hpp
include/waylandcpp/wl_output.hpp
include/waylandcpp/wl_region.hpp
include/waylandcpp/wl_subcompositor.hpp
include/waylandcpp/wl_subsurface.hpp
)
```
To generate files remove --dry-run:
```
waylandcpp-generator --output ./generated --config /usr/share/wayland/wayland.xml
```

Folder `generated/include` is created:
```
$ find ./generated
./generated
./generated/include
./generated/include/waylandcpp
./generated/include/waylandcpp/wl_subsurface.hpp
./generated/include/waylandcpp/wl_keyboard.hpp
./generated/include/waylandcpp/wl_subcompositor.hpp
./generated/include/waylandcpp/wl_shell.hpp
./generated/include/waylandcpp/wl_data_source.hpp
./generated/include/waylandcpp/wl_shm_pool.hpp
./generated/include/waylandcpp/wl_shm.hpp
./generated/include/waylandcpp/wl_output.hpp
./generated/include/waylandcpp/wl_data_offer.hpp
./generated/include/waylandcpp/wl_region.hpp
./generated/include/waylandcpp/wl_seat.hpp
./generated/include/waylandcpp/wl_registry.hpp
./generated/include/waylandcpp/wl_buffer.hpp
./generated/include/waylandcpp/wl_surface.hpp
./generated/include/waylandcpp/wl_shell_surface.hpp
./generated/include/waylandcpp/wl_data_device_manager.hpp
./generated/include/waylandcpp/wl_display.hpp
./generated/include/waylandcpp/wl_compositor.hpp
./generated/include/waylandcpp/wl_callback.hpp
./generated/include/waylandcpp/wl_touch.hpp
./generated/include/waylandcpp/wl_pointer.hpp
./generated/include/waylandcpp/wl_data_device.hpp
```
Header file sample:
```
$ cat ./generated/include/waylandcpp/wl_display.hpp 
#pragma once
#include <string>
#include <vector>
#include "waylandcpp/wire/types.hpp"
#include "waylandcpp/wire/socket.hpp"
#include "waylandcpp/wire/object_builder.hpp"
#include "waylandcpp/wire/buffer_parser.hpp"
#include "waylandcpp/callback.hpp"

namespace waylandcpp::interface {
    class wl_display {
        public:
        using error_cb_t = callback_t<wire::wire_object_id_t, wire::wire_uint_t, wire::wire_string_t>;
        using delete_id_cb_t = callback_t<wire::wire_uint_t>;
        wl_display(wire::WLSocket & sock, wire::wire_object_id_t id_ = 0x0) : sock( sock ), id_( id_ ) {}
        wl_display(wire::WLSocket & sock, wire::wire_object_id_t id_, error_cb_t && error_cb, delete_id_cb_t && delete_id_cb) : sock( sock ), id_( id_ ), error_cb( error_cb ), delete_id_cb( delete_id_cb ) {}
        enum class error_e : uint32_t {
            invalid_object = 0,
            invalid_method = 1,
            no_memory = 2,
            implementation = 3,
        };
        // Requests
        void sync(wire::wire_new_id_t callback) {
            wire::WireObjectBuilder builder(id_, sync_op);
            builder.add(callback);
            sock.write(builder.data(), builder.size());
        }
        void get_registry(wire::wire_new_id_t registry) {
            wire::WireObjectBuilder builder(id_, get_registry_op);
            builder.add(registry);
            sock.write(builder.data(), builder.size());
        }
        // Events
        virtual void error(wire::wire_object_id_t object_id, wire::wire_uint_t code, wire::wire_string_t message) {
            if(error_cb)
            error_cb(object_id, code, message);
        }
        virtual void delete_id(wire::wire_uint_t id) {
            if(delete_id_cb)
            delete_id_cb(id);
        }
        void dispatch(wire::wire_op_t op, wire::WireBufferParser & body) {
            switch(op){
                case error_op:
                    {
                    auto [object_id_v,code_v,message_v] = body.parse<wire::wire_object_id_t,wire::wire_uint_t,wire::wire_string_t>();
                    error(object_id_v,code_v,message_v);
                }
                break;
                case delete_id_op:
                    {
                    auto [id_v] = body.parse<wire::wire_uint_t>();
                    delete_id(id_v);
                }
                break;
            }
        }
        // Utility
        auto id() {
            return id_;
        }
        protected:
        static constexpr wire::wire_op_t sync_op = 0x00;
        static constexpr wire::wire_op_t get_registry_op = 0x01;
        static constexpr wire::wire_op_t error_op = 0x00;
        static constexpr wire::wire_op_t delete_id_op = 0x01;
        wire::WLSocket & sock;
        wire::wire_object_id_t id_;
        error_cb_t error_cb;
        delete_id_cb_t delete_id_cb;
        public:
        const std::string interface = "wl_display"; // This one here is not going to work at least for now, need to rewrite generator
    };
}
```



