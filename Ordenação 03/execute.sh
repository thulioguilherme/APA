#!/bin/bash
for i in {0..2..1}; do
	for j in {0..2..1}; do
		for k in {0..4..1}; do
			for w in {0..5..1}; do
				timeout 5m ./read $i $j $k $w
			done
		done
	done
done
