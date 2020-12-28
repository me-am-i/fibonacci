const express = require('express');
const cors = require('cors');

const app = express();

const addon = require('./build/Release/fibonacci');

const host = '127.0.0.1';
const port = 3001;

app.use(cors());

app.get("/", (req, res) => {

    let current = 0;
    if (req.query.clear) {
        addon.clear();
        res.json({number: 0,
            value: current + 1
        });
    }

    else {
        if (!Number(req.query.value)) {
            current = 0;
        } else {
            current = Number(req.query.value);
        }
    res.json({
            number: addon.get(),
            value: current + 1
        });
    }
});

app.listen(port, host, () => {
 console.log(`Server listens http://${host}:${port}`);
});
