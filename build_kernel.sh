#!/bin/bash

# Check if have toolchain/llvm folder
if [ ! -d "$(pwd)/gcc/" ]; then
   git clone https://android.googlesource.com/platform/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9 gcc -b android-9.0.0_r59 --depth 1 >> /dev/null 2> /dev/null
fi

if [ ! -d "$(pwd)/llvm-sdclang/" ]; then
   git clone https://github.com/proprietary-stuff/llvm-arm-toolchain-ship-10.0 llvm-sdclang --depth 1 >> /dev/null 2> /dev/null
fi

# Export KBUILD flags
export KBUILD_BUILD_USER="Geekmaster21"
export KBUILD_BUILD_HOST="Geekmaster21"

# Export ARCH/SUBARCH flags
export ARCH="arm64"
export SUBARCH="arm64"

# Export ANDROID VERSION
export PLATFORM_VERSION=11
export ANDROID_MAJOR_VERSION=r
export KERNEL_MAKE_ENV="DTC_EXT=$BUILD_KERNEL_DIR/tools/dtc"
export KERNEL_MAKE_ENV+=" DTC_OVERLAY_TEST_EXT=$BUILD_KERNEL_DIR/tools/ufdt_apply_overlay"
export KERNEL_MAKE_ENV+=" CONFIG_BUILD_ARM64_DT_OVERLAY=y"
# Export CCACHE
export CCACHE_EXEC="$(which ccache)"
export CCACHE="${CCACHE_EXEC}"
export CCACHE_COMPRESS="1"
export USE_CCACHE="1"
ccache -M 50G

# Export toolchain/clang/llvm flags
export CROSS_COMPILE="$(pwd)/gcc/bin/aarch64-linux-android-"
export CLANG_TRIPLE="aarch64-linux-gnu-"
export CC="$(pwd)/llvm-sdclang/bin/clang"

# Export if/else outdir var
export WITH_OUTDIR=true

# Clear the console
clear

# Remove out dir folder and clean the source
if [ "${WITH_OUTDIR}" == true ]; then
   if [ -d "$(pwd)/a71" ]; then
      rm -rf a71
   fi
fi

# Build time
if [ "${WITH_OUTDIR}" == true ]; then
   if [ ! -d "$(pwd)/a71" ]; then
      mkdir a71
   fi
fi

if [ "${WITH_OUTDIR}" == true ]; then
 make ARCH=arm64 O=a71 sm7150_sec_defconfig

PATH="/workspace/Kernel/llvm-sdclang/bin:/workspace/Kernel/gcc/bin:${PATH}" \
make -j$(nproc --all) O=a71 \
                      ARCH=arm64 \
                      CC=clang \
                      LLVM=1 \
                      AR=llvm-ar \
                      NM=llvm-nm \
                      OBJCOPY=llvm-objcopy \
                      OBJDUMP=llvm-objdump \
                      STRIP=llvm-strip \
                      CLANG_TRIPLE=aarch64-linux-gnu- \
                      CROSS_COMPILE=aarch64-linux-android-
   tools/mkdtimg create a71/arch/arm64/boot/dtbo.img --page_size=4096 $(find a71/arch -name "*.dtbo")
fi
