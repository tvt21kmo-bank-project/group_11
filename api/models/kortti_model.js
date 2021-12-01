const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const kortti = {
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from kortti where idkortti=?', [id], callback);
  },
  add: function(kortti, callback) {
    // console.log(kortti);
    bcrypt.hash(kortti.PIN, saltRounds, function(err, hash) {
    return db.query(
      'insert into kortti (Korttinumero, PIN, idAsiakas, idTili) values(?,?,?,?)',
      [kortti.Korttinumero, hash, kortti.idAsiakas, kortti.idTili],
      callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where idkortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    bcrypt.hash(kortti.PIN, saltRounds, function(err, hash) {
    return db.query(
      'update kortti set Korttinumero=?, PIN=?, idAsiakas=?, idTili=? where idkortti=?',
      [kortti.Korttinumero, hash, kortti.idAsiakas, kortti.idTili, id],
      callback);
    });
  }
};
module.exports = kortti;