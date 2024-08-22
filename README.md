# Waylandcpp Generator

## Overview

Generates waylandcpp headers for usage with [waylandcpp](https://github.com/nryaskin/waylandcpp)
Uses cppgen library which is placed in current repository to generate C++ code.

### CPPGEN
CPPGEN doesn't support a lot of C++ language features because it is not aimed to create powerfull code generator.
It supports enough features to allow *wayland-generator* to create waylandcpp headers for interfaces from wayland's xml specification.
