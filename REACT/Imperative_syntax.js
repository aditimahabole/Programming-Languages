//---------Html file------------
<html>
    <head>
        <link rel="stylesheet" href="index.css">
        <script crossorigin src="https://unpkg.com/react@17/umd/react.development.js"></script>
        <script crossorigin src="https://unpkg.com/react-dom@17/umd/react-dom.development.js"></script>
        <script src="https://unpkg.com/babel-standalone@6/babel.min.js"></script>
    </head>
    <body>
        <div id="root"></div>
        <script src="index.js" type="text/babel"></script>
    </body>
</html>
//--------Index.js file ---------
// Imperetive way 
const h1 = document.createElement("h1")
const p = document.createElement("p")
p.textContent = "hey there this is imperitive way !"
h1.textContent = "This is an imperative way to program"
h1.className = "header"
p.className = "header"
document.getElementById("root").append(h1)
document.getElementById("root").append(p)
