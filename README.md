# Cobalt

This project is a CLI-based tool which can help get things done (soon)!

## Install

To get the latest bootloader, you must have [Rust](https://www.rust-lang.org/tools/install) installed.

When you run the installer, select _Customize installation_ and make sure to install the Nightly version of Rust.

Then, run the following commands one-by-one in the project directory after Rust is installed.

- `rustup component add rust-src`
- `cargo add bootloader`
- `rustup component add llvm-tools-preview`
- `cargo install bootimage`

Then, to build the binary, run `cargo bootimage`. The binary should be located in `./target/x86_64-cobalt/debug/bootimage-cobalt.bin`.

It is recommended to run the binary in QEMU rather than a real computer by using `qemu-system-x86_64 -drive format=raw,file=path/to/bootimage-cobalt.bin`.

## Looking for the old Cobalt?

Go to the [archive](https://github.com/arnavthorat78/cobalt/tree/archive) branch to see the legacy code of Cobalt!
