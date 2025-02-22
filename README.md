# MOS6502

A MOS6502 emulator in pure C.

# Building

Use `make` to trigger Meson and Ninja.

# Tests

Tests are configured to run with `make test`. These tests are intended as a way if knowing how much instructions I've implemented. Further tests will be written testing the vm against concrete assembly programs. An example is a Fibonacci sequence program.

# Problems?

My BRK needs an immediate operand which has the semantics of a break signature. If you don't want to use this feature, follow any BRK with a NOP to avoid issues.
