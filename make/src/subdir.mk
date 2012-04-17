################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Disparo.cpp \
../src/ElementoGrafico.cpp \
../src/Enemigo.cpp \
../src/Hardware.cpp \
../src/Juego.cpp \
../src/Jugador.cpp 

OBJS += \
./src/Disparo.o \
./src/ElementoGrafico.o \
./src/Enemigo.o \
./src/Hardware.o \
./src/Juego.o \
./src/Jugador.o 

CPP_DEPS += \
./src/Disparo.d \
./src/ElementoGrafico.d \
./src/Enemigo.d \
./src/Hardware.d \
./src/Juego.d \
./src/Jugador.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


