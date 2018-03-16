#!/bin/bash

gst-launch-1.0 filesrc location=../img/video ! videoconvert ! qreader ! videoconvert ! ximagesink
