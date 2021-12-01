var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

const helmet = require('helmet');
const cors = require('cors');
var app = express();

app.use(helmet());
app.use(cors());
const dotenv = require('dotenv');
dotenv.config();

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var asiakasRouter = require('./routes/asiakas');
var tiliRouter = require('./routes/tili');
var tilitapahtumatRouter = require('./routes/tilitapahtumat');
var korttiRouter = require('./routes/kortti');



app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/asiakas', asiakasRouter);
app.use('/tili', tiliRouter);
app.use('/tilitapahtumat', tilitapahtumatRouter);
app.use('/kortti', korttiRouter);

module.exports = app;
