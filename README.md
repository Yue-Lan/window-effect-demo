# window-effect-demo

## imgblur
### 原图
![原图](screenshot/test.png)

### 模糊后
![模糊后](screenshot/testblur.png)

## KWindowEffects
![整个屏幕截屏](screenshot/window-effect-whole-screen.png)

![窗口截屏](screenshot/window-effect-current-window.png)

通过这两张截图可以比较容易看出KWindowEffects的实现并不是直接对窗口进行模糊，而是对窗口下面的内容进行模糊，只是因为窗口是透明的，所以看上去像是窗口模糊了一样。