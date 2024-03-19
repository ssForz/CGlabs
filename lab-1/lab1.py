import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider


fig, ax = plt.subplots(figsize=(7, 7))
# ax = plt.subplot(111, projection = 'polar')
plt.subplots_adjust(left=0.1, bottom=0.25)


a_init = 1.0
b_init = 1.0
A_init = 0
B_init = 8*np.pi
phi = np.linspace(A_init, B_init, 1000)
x = a_init*phi - a_init*np.sin(phi)
y = a_init - b_init*np.cos(phi)


line, = ax.plot(x, y)


ax.set_xlim(-max(abs(x) + 0.5), max(abs(x) + 0.5))
ax.set_ylim(-max(abs(y) + 0.5), max(abs(y) + 0.5))


# ax.grid(True, color='black', linestyle='-', linewidth=0.5)
# ax.spines['polar'].set_visible(True)
# ax.spines['polar'].set_linewidth(2)


ax = plt.gca()
ax.spines['left'].set_position('center')
ax.spines['bottom'].set_position('center')
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)


# global arX
# global pX
# global arY
# global pY
arX = ax.annotate("", xy=(max(abs(x) + 0.5), 0), xytext=(-max(abs(x) + 0.5), 0), arrowprops=dict(arrowstyle="->", color="k"))
pX = ax.annotate("X", xy=(max(abs(x) + 0.5), 0), color="k")
arY = ax.annotate("", xy=(0,max(abs(y) + 0.5)), xytext=(0,-max(abs(y) + 0.5)), arrowprops=dict(arrowstyle="->", color="k"))
pY = ax.annotate("Y", xy=(0, max(abs(y) + 0.5)), color="k")


a_slider = plt.axes([0.1, 0.1, 0.65, 0.03], facecolor='lightgoldenrodyellow')
b_slider = plt.axes([0.1, 0.07, 0.65, 0.03], facecolor='lightgoldenrodyellow')
A_slider = plt.axes([0.1, 0.04, 0.65, 0.03], facecolor='lightgoldenrodyellow')
B_slider = plt.axes([0.1, 0.01, 0.65, 0.03], facecolor='lightgoldenrodyellow')
bslider = Slider(b_slider, 'b', -10.0, 10.0, valinit=b_init)
Bslider = Slider(B_slider, 'B', 0, 8*np.pi, valinit=B_init)
aslider = Slider(a_slider, 'a', -10.0, 10.0, valinit=a_init)
Aslider = Slider(A_slider, 'A', 0, 8*np.pi, valinit=A_init)

def update(val):
    b = bslider.val
    aslider.valmax = b;
    a = aslider.val
    bslider.valmin = a;
    B = Bslider.val
    Aslider.valmax = B;
    A = Aslider.val
    Bslider.valmin = A
    phi = np.linspace(A, B, 1000)
    x_new = a*phi - a*np.sin(phi)
    y_new = a - b*np.cos(phi)
    line.set_ydata(y_new)
    line.set_xdata(x_new)
    global arX
    global arY
    global pX
    global pY
    arX.remove()
    arY.remove()
    pX.remove()
    pY.remove()
    arX = ax.annotate("", xy=(max(abs(x_new) + 0.5), 0), xytext=(-max(abs(x_new) + 0.5), 0), arrowprops=dict(arrowstyle="->", color="k"))
    pX = ax.annotate("X", xy=(max(abs(x_new) + 0.5), 0), color="k")
    arY = ax.annotate("", xy=(0, max(abs(y_new + 0.5))), xytext=(0,-max(abs(y_new) + 0.5)), arrowprops=dict(arrowstyle="->", color="k"))
    pY = ax.annotate("Y", xy=(0, max(abs(y_new) + 0.5)), color="k")
    ax.set_xlim(-max(abs(x_new) + 0.5), max(abs(x_new) + 0.5))
    ax.set_ylim(-max(abs(y_new) + 0.5), max(abs(y_new) + 0.5))
    fig.canvas.draw_idle()

aslider.on_changed(update)
bslider.on_changed(update)
Aslider.on_changed(update)
Bslider.on_changed(update)

plt.show()
