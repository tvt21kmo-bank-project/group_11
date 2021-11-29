const db = require('../database');
const tilitapahtumat = {
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where idtilitapahtumat=?', [id], callback);
  },
  add: function(tilitapahtumat, callback) {
    console.log(tilitapahtumat);
    return db.query(
      'insert into tilitapahtumat (Paivays, Tapahtuma, Summa, idTili, idKortti) values(?,?,?,?,?)',
      [tilitapahtumat.Paivays, tilitapahtumat.Tapahtuma, tilitapahtumat.Summa, tilitapahtumat.idTili, tilitapahtumat.idKortti],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where idtilitapahtumat=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set Paivays=?, Tapahtuma=?, Summa=?, idTili=?, idKortti=? where idtilitapahtumat=?',
      [tilitapahtumat.Paivays, tilitapahtumat.Tapahtuma, tilitapahtumat.Summa, tilitapahtumat.idTili, tilitapahtumat.idKortti, id],
      callback
    );
  }
};
module.exports = tilitapahtumat;