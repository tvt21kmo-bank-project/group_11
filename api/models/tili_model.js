const db = require('../database');
const tili = {
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from tili where idtili=?', [id], callback);
  },
  add: function(tili, callback) {
    console.log(tili);
    return db.query(
      'insert into tili (idOmistaja, Tilinumero, Saldo, Tilin_tyyppi, Luottoraja) values(?,?,?,?,?)',
      [tili.idOmistaja, tili.Tilinumero, tili.Saldo, tili.Tilin_tyyppi, tili.Luottoraja],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili where idtili=?', [id], callback);
  },
  update: function(id, tili, callback) {
    return db.query(
      'update tili set idOmistaja=?, Tilinumero=?, Saldo=?, Tilin_tyyppi=?, Luottoraja=? where idtili=?',
      [tili.idOmistaja, tili.Tilinumero, tili.Saldo, tili.Tilin_tyyppi, tili.Luottoraja, id],
      callback
    );
  }
};
module.exports = tili;