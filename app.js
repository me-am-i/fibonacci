const express = require('express');
const app = express();
const handlebars = require('express-handlebars');

const addon = require('./build/Release/fibonacci');

const host = '127.0.0.1';
const port = 3000;

app.engine('handlebars', handlebars({defaultLayout: 'main'}));
app.set('views', './views');
app.set('view engine', 'handlebars');
app.enable('view cache');

app.get("/", (req, res) => {
    let current;
    if (!Number(req.query.value)){
        current = 0;
    } else current = Number(req.query.value);
    res.render('home', {
        number: addon.get(current),
        value: current + 1
    });

});

app.listen(port, host, () => {
 console.log(`Server listens http://${host}:${port}`);
});
