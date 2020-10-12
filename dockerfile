# Definimos OS base
FROM ubuntu:20.04

ENV TZ=America/Costa_Rica
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime \
    && echo $TZ > /etc/timezone

# Algo de información
LABEL mantainer="Grupo AVL_Tree"
LABEL version="1.0"
LABEL description="Custom docker image for a Gtest AVL tree"

# Se elije el usuario root
USER root
RUN apt-get update \
    && apt-get --yes --no-install-recommends install \
        build-essential cmake libgtest-dev \
    && cd /usr/src/gtest/ \
    && cmake CMakeLists.txt \
    && make

# Se crea la carpeta del proyecto
RUN mkdir -p /home/avl_tree/tests

# Se copian los archivos
COPY include /home/avl_tree/tests/include
COPY src /home/avl_tree/tests/src
COPY test /home/avl_tree/tests/test
COPY CMakeLists.txt /home/avl_tree/tests/CMakeLists.txt

# Ejecución de los de las pruebas de GTest
# Se crea un directorio de contrucción de la prueba
# Se mueve dentro de él para ejecutar el archivo CMkaeLists.txt
# Se ejecuta el archivo de CMake
# Se crea el ejecutable exe_gft
# Se copia el ejecutable en la dirección estándar suministrada
RUN mkdir /home/avl_tree/tests/build \ 
    && cd /home/avl_tree/tests/build \
    && cmake .. \
    && make \
    && cp exe_gft /usr/bin/run_unittest

# DEBUG: se imprime un mensaje de éxito al completar el proceso
RUN echo "\nSe completó la operación con éxito\n"
