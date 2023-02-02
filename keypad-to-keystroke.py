import serial
import pydirectinput
import pyautogui

def pressFast(key, N=500):
	pydirectinput.PAUSE=0.01

while True:
	with serial.Serial('COM4', 9600) as ser:
		x = ser.read().decode('utf-8')
		print(x)
		pydirectinput.press(x)