const mysql = require('mysql');
//const con = 'mysql://root:testi@localhost:3306/pankki';
const connection = mysql.createPool(process.env.MYSQL);
//const connection = mysql.createPool(con);
module.exports = connection;