$(function () {
    console.log("ready!");
});

function sendData(sentData) {
    $.ajax({
        url: "http://"+window.ipaddress+"/",
        data: sentData,
        method: "get"
    });
}

function getData(callback) {
    $.ajax({
        url: "http://"+window.ipaddress+"/",
        data: "get",
        method: "get"
    });
}
