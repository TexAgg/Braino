#! /usr/bin/python

# Python script which reads facebook messages and stores them.

import os
from bs4 import BeautifulSoup
from collections import defaultdict
import json
import mysql.connector
import sys
import argparse

# http://stackoverflow.com/a/31137935/5415895
#reload(sys)
#sys.setdefaultencoding('utf-8')

config = {
  'user': 'root',
  'password': 'apple',
  'host': '127.0.0.1',
  'database': 'braino',
  'raise_on_warnings': True,
}

messages_data = "/home/matt/Dropbox/Programming/AI/Braino/data/facebook_data/html/messages.htm"

# https://github.com/TexAgg/TamuHack/blob/master/hackgetter.py
def get_data():
	file = open(messages_data, 'r')
	soup = BeautifulSoup(file.read(), 'html.parser')
	messages = soup.find_all("p")

	# http://stackoverflow.com/a/960753/5415895
	data = defaultdict(list)
	for i in range(len(messages)-1):
		# Just ignore all the characters that don't work.
		message = messages[i].getText()[:191].encode("utf-8", 'ignore')
		reply = messages[i+1].getText()[:191].encode("utf-8", 'ignore')
		if message != '':
			data[message].append(reply)
	with open("data.json", "w") as f:
		json.dump(data, f, ensure_ascii=False)

def store_data():
	f = open('data.json')
	data = json.load(f)

	cnx = mysql.connector.connect(**config)
	cursor = cnx.cursor()

	for phrase in data.keys():
		query = "INSERT IGNORE INTO phrases (phrase) VALUES (%(phrase)s) ON DUPLICATE KEY UPDATE id=id;"
		cursor.execute(query, {'phrase':phrase})
		# Get id
		query = "SELECT `id` FROM phrases WHERE phrase=(%(phrase)s)"
		cursor.execute(query, {'phrase':phrase})
		id = cursor.next()[0]
		print id
		for reply in data[phrase]:
			query = "INSERT IGNORE INTO responses (parent, response) VALUES (" + str(id) + ", %(reply)s)"
			cursor.execute(query, {'reply':reply})

	cnx.commit()
	cursor.close()
	cnx.close()

if __name__ =="__main__":
	parser = argparse.ArgumentParser(description='Generate data.')
	parser.add_argument("-d", "--data", help='Location of the data. Default is ' + messages_data, required = False)
	parser.add_argument('-g', '--get_data', help="Parse the data from the Facebook download.", action='store_true', required=False)
	parser.add_argument('-s', '--store_data', action='store_true', help='Store the data in the database.')
	args = vars(parser.parse_args())

	if args['data']:
		messages_data = args['data']
	if args['get_data']:
		get_data()
	if args['store_data']:
		store_data()
	if not args:
		print "Run with the -h flag to see instructions."