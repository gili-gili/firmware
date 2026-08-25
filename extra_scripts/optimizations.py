#!/usr/bin/env python3

# NOTE: See SCons: 7.2, Appendix A, Appendix D

Import("env")  # pyrefly: ignore[unknown-name]
env: dict


def check_env_name(name: str) -> bool:
    if name not in env:
        print(f"WARN: {name} not found in env, skipping")
        return False
    return True


def filter_env(names: set[str], flags: set[str]) -> None:
    for name in names:
        if check_env_name(name) is False:
            continue

        original_flags = env[name]
        remaining_flags: list = []

        remaining_flags = [flag for flag in original_flags if flag not in flags]

        env[name] = remaining_flags


def append_env(names: set[str], flags: set[str]) -> None:
    for name in names:
        if check_env_name(name) is False:
            continue

        for flag in flags:
            print(f"Appending {flag} to {name}")
            env.Append(name=flag)


filter_env_names = {
    "ASFLAGS",
    "CCFLAGS",
    "LINKFLAGS",  # SCons specific
    "CFLAGS",
    "CXXFLAGS",
    "LDFLAGS",  # general
}
filter_flags = {"-Os", "-fno-lto"}

filter_env(names=filter_env_names, flags=filter_flags)
append_env({"CCFLAGS"}, {"-ffunction-sections", "-fdata-sections"})
append_env({"LINKFLAGS"}, {"--gc-sections"})

if "OPTIMIZATION_OFAST" in env["CPPDEFINES"]:
    append_env({"CCFLAGS"}, {"-Ofast"})
if "OPTIMIZATION_O3" in env["CPPDEFINES"]:
    append_env({"CCFLAGS"}, {"-O3"})
if "OPTIMIZATION_LTO" in env["CPPDEFINES"]:
    append_env({"CCFLAGS", "LINKFLAGS"}, {"-flto", "--no-fat-lto-objects"})
