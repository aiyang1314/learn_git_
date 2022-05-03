// let fs = require("fs");
// fs.open("hello.txt", "w", function (err, fd) {
//     if (!err) {
//         console.log("打开成功");
//         fs.write(fd, "第二次", function (err) {
//             if (!err) {
//                 console.log("写入成功");
//             }
//         })
//     } else {
//         console.log(err);
//     }
// })
//引入express模块
const express = require("express");
//创建应用对象
const app = express();
//创建路由规则
//request 是对请求报文的封装
//response 是对响应报文的封装
app.get("/server", (request, response) => {
    //设置响应头 设置允许跨域
    response.setHeader("Access-Control-Allow-Origin", '*');
    //设置响应体
    response.send("hello AJAX");
});
//监听端口启动服务
app.listen(8000, () => {
    console.log('服务已经启动,8000端口监听中...');
});