$(function () {
    console.log("ready!");
});

function setData(sentData) {
    $.ajax({
        url: "http://" + window.ipaddress + "/setData?data=" + sentData,
        //crossDomain: true,
        contentType: "text/plain",
        dataType: "text/plain",
        method: "get",
        success: function (data) {
            console.log(data);
        }
    });
}

function getData(callback) {
    $.ajax({
        url: "http://" + window.ipaddress + "/getData",
        //crossDomain : true,
        method: "get",
        success: function (data) {
            callback(data);
        }
    });
}
