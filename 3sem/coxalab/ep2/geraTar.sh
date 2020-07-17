#!/usr/bin/env bash

mkdir entrega
cp -r *.ipynb *.pdf csvs images *.tex *.org entrega
tar -cvf entrega.tar entrega
rm -rf entrega
