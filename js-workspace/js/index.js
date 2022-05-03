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
const express = require("express");
//创建应用对象
const app = express();
//创建路由规则
app.get("/", (request, response) => {
    //设置响应
    response.send("hello express");
});
//监听端口启动服务
app.listen(8000, () => {
    console.log('服务已经启动，8000端口监听中...');
});