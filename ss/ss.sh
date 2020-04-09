 
#---------------
# Setting env
export PROJECT_DIR=$(pwd)
export INSTALL_DIR=${PROJECT_DIR}/build

# Setting version
export cares_ver=1.16.0
export libev_ver=4.33
export libsodium_ver=1.0.18
export mbedtls_ver=2.16.5
export pcre_ver=8.44
export ss_ver=3.3.4

# Download and extract dependencies
wget https://c-ares.haxx.se/download/c-ares-${cares_ver}.tar.gz
tar xzf c-ares-${cares_ver}.tar.gz

wget http://dist.schmorp.de/libev/libev-${libev_ver}.tar.gz
tar xzf libev-${libev_ver}.tar.gz

wget https://download.libsodium.org/libsodium/releases/libsodium-${libsodium_ver}.tar.gz
tar xzf libsodium-${libsodium_ver}.tar.gz

wget https://tls.mbed.org/download/mbedtls-${mbedtls_ver}-apache.tgz
tar xzf mbedtls-${mbedtls_ver}-apache.tgz

wget https://ftp.pcre.org/pub/pcre/pcre-${pcre_ver}.tar.gz
tar xzf pcre-${pcre_ver}.tar.gz

wget https://github.com/shadowsocks/shadowsocks-libev/releases/download/v${ss_ver}/shadowsocks-libev-${ss_ver}.tar.gz
tar xzf shadowsocks-libev-${ss_ver}.tar.gz


#---------------
# build dependencies
# build c-ares
cd ${PROJECT_DIR}/c-ares-${cares_ver}
./configure --prefix=${INSTALL_DIR}/cares --disable-shared
make && make install

# build libev
cd ${PROJECT_DIR}/libev-${libev_ver}
./configure --prefix=${INSTALL_DIR}/libev --disable-shared
make && make install

# build libsodium
cd ${PROJECT_DIR}/libsodium-${libsodium_ver}
./configure --prefix=${INSTALL_DIR}/sodium --disable-ssp --disable-shared
make && make install

# build mbedTLS
cd ${PROJECT_DIR}/mbedtls-${mbedtls_ver}
LDFLAGS="-static"
make DESTDIR=${INSTALL_DIR}/mbedtls install

# build pcre
cd ${PROJECT_DIR}/pcre-${pcre_ver}
./configure --prefix=${INSTALL_DIR}/pcre --disable-shared --enable-utf8 --enable-unicode-properties
make && make install



#---------------
# build shadowsocks
cd ${PROJECT_DIR}/shadowsocks-libev-${ss_ver}
LIBS="-lpthread -lm" LDFLAGS="-Wl,-static -static -static-libgcc -L${INSTALL_DIR}/libev/lib" CFLAGS="-I${INSTALL_DIR}/libev/include" ./configure --prefix=${INSTALL_DIR}/shadowsocks --disable-ssp --disable-documentation --with-mbedtls=${INSTALL_DIR}/mbedtls --with-pcre=${INSTALL_DIR}/pcre --with-sodium=${INSTALL_DIR}/sodium --with-cares=${INSTALL_DIR}/cares
sed -i 's/-Werror//' src/Makefile
make && make install
# strip exe
strip ${INSTALL_DIR}/shadowsocks/bin/ss-*



