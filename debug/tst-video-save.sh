#!/bin/bash

gst-launch-1.0 v4l2src ! videoconvert ! videocrop top=0 bottom=0 left=0 right=1280 ! tee name=t ! queue ! qreader ! videoconvert ! ximagesink t. ! queue ! videoconvert !  ximagesink
#                                                                                             save. ! queue ! videoconvert !  y4menc ! filesink location=tst.mpeg
#                                                                                             t. ! queue ! videoconvert !  ximagesink #y4menc ! filesink location=tst.mpeg
