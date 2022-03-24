# Carlos Pineda

from .widgets import widget_list, taskbar, taskbar2, secondary_widgets

from libqtile.config import Screen
from libqtile import bar, widget
from libqtile.log_utils import logger

import subprocess

screens = [
    Screen(
        top=bar.Bar(
            widgets=widget_list,
            size=25,
            background="#3b4252.00",
            border_color=["#3b4252.00", "#3b4252.00", "#3b4252.00", "#3b4252.00"],
            border_width=[4, 4, 4, 4],
            opacity=1,
            margin=[4, 8, 0, 8],
        ),
        bottom=bar.Bar(
            widgets=taskbar,
            size=25,
            background="#3b4252.00",
            border_color=["#3b4252.00", "#3b4252.00", "#3b4252.00", "#3b4252.00"],
            border_width=[0, 0, 2, 0],
            opacity=1,
            margin=[4, 8, 0, 8],
        )
    ),
]

xrandr = "xrandr | grep -w 'connected' | cut -d ' ' -f 2 | wc -l"

command = subprocess.run(
    xrandr,
    shell=True,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
)

if command.returncode != 0:
    error = command.stderr.decode("UTF-8")
    logger.error(f"Failed counting monitors using {xrandr}:\n{error}")
    connected_monitors = 1
else:
    connected_monitors = int(command.stdout.decode("UTF-8"))

if connected_monitors > 1:
    for _ in range(1, connected_monitors):
        screens.append(Screen(
                            bottom=bar.Bar(
                                widgets=taskbar2,
                                size=25,
                                background="#3b4252.00",
                                border_color=["#3b4252.00", "#3b4252.00", "#3b4252.00", "#3b4252.00"],
                                border_width=[0, 0, 2, 0],
                                opacity=1,
                                margin=[4, 8, 0, 8],
                            ),
                            top=bar.Bar(
                                widgets=secondary_widgets,
                                size=25,
                                background="#3b4252.00",
                                border_color=["#3b4252.00", "#3b4252.00", "#3b4252.00", "#3b4252.00"],
                                border_width=[4, 4, 4, 4],
                                opacity=1,
                                margin=[4, 8, 0, 8],
                            )
        ))