################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Drawing.cpp \
../src/Shape.cpp \
../src/main.cpp 

OBJS += \
./src/Drawing.o \
./src/Shape.o \
./src/main.o 

CPP_DEPS += \
./src/Drawing.d \
./src/Shape.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/adam/Dropbox/Swinburne/HIT3172/GitHub/lab02/core_exercises/drawing/lib" -O0 -g3 -Wall -c -fmessage-length=0 -arch i386 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

