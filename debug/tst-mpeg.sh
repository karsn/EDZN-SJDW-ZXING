#!/bin/bash

gst-launch-1.0 filesrc location=../img/tst.mpeg ! y4mdec ! videoconvert ! ximagesink
