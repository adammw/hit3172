################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Card.cpp \
../src/GraphicalCard.cpp \
../src/main.cpp 

OBJS += \
./src/Card.o \
./src/GraphicalCard.o \
./src/main.o 

CPP_DEPS += \
./src/Card.d \
./src/GraphicalCard.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/adam/Dropbox/Swinburne/HIT3172/GitHub/lab01/extension_exercises/blackjack-graphical-iter01/lib" -O0 -g3 -Wall -c -fmessage-length=0 -arch i386 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


