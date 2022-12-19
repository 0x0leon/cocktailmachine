var express = require('express');

var router = express.Router();

/* GET users listing. */
router.get('/', function (req, res, next) {
    res.send('index');
});

router.get('/dashboard', function (req, res, next) {
    // send motordata 
    // send bottledata
    

    // send commands to arduino
    res.json([
        {
            x: 1,
            y: 10
        }, {
            x: 2,
            y: 10
        }, {
            x: 3,
            y: 10
        }, {
            x: 4,
            y: 10
        }
    ])
})

module.exports = router;
