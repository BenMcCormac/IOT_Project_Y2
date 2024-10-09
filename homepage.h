String homePagePart1 = F(R"=====(<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, viewport-fit=cover">
  <title>IOT Apiary Website</title>

  <style>
    *{
    margin:0px;
    padding:0px;
    font-family: Arial, Helvetica, sans-serif;
    box-sizing: border-box;
    }
    body {       
        background-color:rgb(255, 226, 183);
    }
    .flex-container{
      display: flex;
      flex-direction: row;
      justify-content: center;
      align-content: stretch;
    }
    @media (max-width: 800px) {
      .flex-container{
        display: flex;
        flex-flow: wrap row;
        justify-content: center;
        align-content: stretch;
        padding-left: 30px;
      }
    }
    .flex-keypad{
      display: flex;
      flex-direction: row;
      align-items: center;
      justify-content: center;
    }
    .myButton {
      background-color: LightGrey;
      margin: 10px;
      padding: 10px;
      width: 20%;
      font-size: 30px;
      text-align: center;
    }
    .myButton:hover{
      background-color: green;
    }
    #Head{
      width: 100%;
      float: center;
    }
    #Apiary1{
      width: 450px;
      height: 100%;
      float: center;
      background-color: rgb(193, 255, 193);
      min-height: 400px;
      text-align: center;
      margin-bottom: 25px;
    }
    #Apiary2{
      width: 450px;
      height: 100%;
      float: center;
      background-color:rgb(193, 255, 193);
      min-height: 400px;
      text-align: center;
      margin-bottom: 25px;
    }
    #Apiary3{
      width: 450px;
      height: 100%;
      float: center;
      background-color: rgb(193, 255, 193);
      min-height: 400px;
      text-align: center;
      margin-bottom: 25px;
    }
    #Text{
        text-align: center;
        float: left;
    }
    h1{
        font: bold;
        font-size: 40px;                    
        color: rgb(7, 6, 2);
        text-align: center;
    }
    hr{
        color:rgb(100, 100, 50);
    }
    p{
        font-size: 28px;
        color: rgb(0, 0, 0);
    }
    th, td {
        font-size: 25px;
        padding: 8px;
        text-align: left;
        border-bottom: 1px solid #ddd;
    }
    </style>
</head>
<body>
  <div id="Head">
    <h1>IOT Apiary</h1>
  </div>
  <hr>

  <div class="flex-container">
      <div id="Apiary1">
        <h3>Apiary #1</h3>
        
        <table>
          <tr>
            <th>Sensor</th>
            <th>Value</th>
            <th>Unit</th>
          </tr>
          <tr>
            <td>Temperature</td>
            <td><i>)=====");
            String homePagePart2 = F(R"=====(</i></td>
            <td>Degree Celsius</td>
          </tr>
          <tr>
            <td>Humidity</td>
            <td><i>)=====");
            String homePagePart3 = F(R"=====(</i></td>
            <td>Percent</td>
          </tr>
          <tr>
            <td>Light</td>
            <td><i>)=====");
            String homePagePart4 = F(R"=====(</i></td>
            <td>Lumens</td>
          </tr> 
        </table>
        
        <hr>

        <div class="flex-keypad">
          <button class="myButton" onclick="fetch('/sentKeyPressToWebServer?button=1')">Lock</button>
        </div>

        <iframe width="425" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/2412101/charts/1?bgcolor=%23ffffff&color=%23d62020&results=20"></iframe>

        <iframe width="425" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/2412101/charts/2?bgcolor=%23ffffff&color=%23d62020&results=20"></iframe>

        <iframe width="400" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/2412101/widgets/855458"></iframe>
      </div>

      <div id="Apiary2">
        <h3>Apiary #2</h3>
        
        <p>This is where all the information from the sensors will show up<br></p>
        <p>A table will appear below here<br><br></p>
        
        <table>
          <tr>
            <th>Sensor</th>
            <th>Value</th>
            <th>Unit</th>
          </tr>
          <tr>
            <td>Temperature</td>
            <td><i>Sample No.</i></td>
            <td>Degree Celsius</td>
          </tr>
          <tr>
            <td>Humidity</td>
            <td><i>Sample No.</i></td>
            <td>Percent</td>
          </tr>
          <tr>
            <td>Light</td>
            <td><i>Yes or No (threshold). Sample No.</i></td>
            <td>Lumens</td>
          </tr> 
        </table>
        
        <hr>
        
        <div class="flex-keypad">
          <button class="myButton" onclick="fetch('/sentKeyPressToWebServer?button=2')">Lock</button>
        </div>

        <iframe width="425" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/2412101/charts/1?bgcolor=%23ffffff&color=%23d62020&results=20"></iframe>

        <iframe width="425" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/2412101/charts/2?bgcolor=%23ffffff&color=%23d62020&results=20"></iframe>

        <iframe width="400" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/2412101/widgets/855458"></iframe>
      </div>
        
      <div id="Apiary3">
        <h3>Apiary #3</h3>
        
        <p>This is where all the information from the sensors will show up<br></p>
        <p>A table will appear below here<br><br></p>
        
        <table>
          <tr>
            <th>Sensor</th>
            <th>Value</th>
            <th>Unit</th>
          </tr>
          <tr>
            <td>Temperature</td>
            <td><i>Sample No.</i></td>
            <td>Degree Celsius</td>
          </tr>
          <tr>
            <td>Humidity</td>
            <td><i>Sample No.</i></td>
            <td>Percent</td>
          </tr>
          <tr>
            <td>Light</td>
            <td><i>Yes or No (threshold). Sample No.</i></td>
            <td>Lumens</td>
          </tr> 
        </table>
        
        <hr>
        
        <div class="flex-keypad">
          <button class="myButton" onclick="fetch('/sentKeyPressToWebServer?button=3')">Lock</button>
        </div>
      </div>
  </div>
</body>
</html>)=====");