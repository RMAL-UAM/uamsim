#! /usr/bin/bash

docker-compose build && docker-compose up -d && docker attach uam-official_app_1
