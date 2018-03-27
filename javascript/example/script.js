$( document ).ready(function() {
    
    window.ipaddress="0.0.0.0" // ip address of your arduino - read it from the console    
    
    $("#sendButton").on("click",function(){ //when the sendButton has been clicked
        
        var valueToSend=$("#valueToSend").val(); //get the value to send from the textbox with id=valueToSend
        console.log("The value to send is: "+valueToSend); //log the value on console
        
        $("#sentValue").text(valueToSend); //show the valueToSend
        
        setData(valueToSend);
        
    });
    
    $("#ipaddress").on("change",function(){
        window.ipaddress=$("#ipaddress").val();
        console.log("New IP: "+window.ipaddress);
    });
    
    getDataInterval(onReceivedData,1000);    
    
});

function onReceivedData(receivedData){
    console.log("I received from Arduino: "+receivedData);
    $("#receivedValue").text(receivedData);
}