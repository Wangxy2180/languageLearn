# GO

go的三种运行方式
1. 使用源码直接运行
```go
go run hello.go
```
2. 构建成可执行文件，再运行
```go
go build hello.go
./hello
```

~~需要设置一个`GOPATH`，只要把它放在`src`文件夹下就行~~

这两个文件都是在`package main`中

运行方法
```go
go run hello.go basic_grammar.go
```

构造方法
```go
go build hello.go basic_grammar.go
```

### 问题
我在导入gopath目录下的包时报错“package xxx is not in GOROOT“，编译器没有去gopath下找包，查了一下原因是GO111MODULE没有关， gomod 和 gopath 两个包管理方案，并且相互不兼容，在 gopath 查找包，按照 goroot 和多 gopath 目录下 src/xxx 依次查找。在 gomod 下查找包，解析 go.mod 文件查找包，mod 包名就是包的前缀，里面的目录就后续路径了。在 gomod 模式下，查找包就不会去 gopath 查找，只是 gomod 包缓存在 gopath/pkg/mod 里面。

解决方法
把GO111MODULE置为off就行了。

```
go env -w GO111MODULE=off
```

go 的package调用顺序
![](https://gitee.com/wangxy2180/imagehost/raw/master/codingTech/go_package.png)

但是建议还是使用gomodule管理包

#### GOPROXY
国内代理：
```
https://mirrors.aliyun.com/goproxy
https://goproxy.cn,direct
```

```
go env -w GOPROXY=https://goproxy.cn,direct
```

设置了goproxy，就不用再设置gosumdb了，这是个做校验和的网站

```
go mod init 当前模块名称
```

go run会自动下载

在go.mod的路径下
```
go get github.com/aceld/zinx/znet
go get github.com/aceld/zinx/ziface
```
他会生成GOPATH/pkg文件夹

这样就可以把你的项目放在任何地方，不需要放在GOPATH下了

然后运行main.go，就能执行成功了