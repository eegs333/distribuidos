################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Fecha.cpp \
../src/practica2.cpp \
../src/prog2.2.cpp 

OBJS += \
./src/Fecha.o \
./src/practica2.o \
./src/prog2.2.o 

CPP_DEPS += \
./src/Fecha.d \
./src/practica2.d \
./src/prog2.2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


