let fs = require("fs");
fs.open("hello.txt", "w", function (err, fd) {
    if (!err) {
        console.log("打开成功");
        fs.write(fd, "第一次", function (err) {
            if (!err) {
                console.log("写入成功");
            }
        })
    } else {
        console.log(err);
    }
})