################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Coordenada.cpp \
../src/Ortoedro.cpp \
../src/Rectangulo.cpp \
../src/prog4-1.cpp 

OBJS += \
./src/Coordenada.o \
./src/Ortoedro.o \
./src/Rectangulo.o \
./src/prog4-1.o 

CPP_DEPS += \
./src/Coordenada.d \
./src/Ortoedro.d \
./src/Rectangulo.d \
./src/prog4-1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


