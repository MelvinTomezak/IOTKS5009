from machine import Pin, ADC, UART
from umodbus.serial import ModbusRTU

sensor1_pin = Pin(2, Pin.IN)
sensor2_pin = ADC(Pin(34))
sensor2_pin.atten(ADC.ATTN_11DB)

uart = UART(1, baudrate=9600, tx=17, rx=16)
modbus = ModbusRTU(uart, slave_address=1)

holding_registers = [0] * 10

def update_registers():
    holding_registers[0] = sensor1_pin.value()
    holding_registers[1] = sensor2_pin.read()

while True:
    update_registers()
    modbus.process(holding_registers)