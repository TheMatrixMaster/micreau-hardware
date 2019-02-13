#Read Temperature and Humidity Serial Data from Arduino
import serial
import requests

ard = serial.Serial('COM5', 9600, timeout=.5, parity=serial.PARITY_NONE)

micreau_url = "https://micreau-dev.herokuapp.com/api/"

sensorid = 0

while True:
	#Read raw serial data from arduino COM5 port
	msg = ard.readline()
	if msg: 
		clean_msg = str(msg).split("Y")[1]

		DHT_TEMP = clean_msg.split(' ')[0]
		DHT_HUM = clean_msg.split(' ')[1]
		DS18B20_TEMP = clean_msg.split(' ')[2]

		hum_req = requests.request('POST', url=(micreau_url + 'humidity'), json={'humidity': DHT_HUM})
		temp_req = requests.request('POST', url=(micreau_url + 'temperature'), json={'temperature': DS18B20_TEMP})
		

		print(temp_req, hum_req)