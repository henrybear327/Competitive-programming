
// Provide a default path to dwr.engine
if (dwr == null) var dwr = {};
if (dwr.engine == null) dwr.engine = {};
if (DWREngine == null) var DWREngine = dwr.engine;

if (judgeService == null) var judgeService = {};
judgeService._path = '/vjudge/dwr';
judgeService.getProblemStatus = function(p0, callback) {
  dwr.engine._execute(judgeService._path, 'judgeService', 'getProblemStatus', p0, callback);
}
judgeService.fetchDescriptions = function(p0, callback) {
  dwr.engine._execute(judgeService._path, 'judgeService', 'fetchDescriptions', p0, callback);
}
judgeService.findProblemSimple = function(p0, p1, callback) {
  dwr.engine._execute(judgeService._path, 'judgeService', 'findProblemSimple', p0, p1, callback);
}
judgeService.getRankInfo = function(p0, callback) {
  dwr.engine._execute(judgeService._path, 'judgeService', 'getRankInfo', p0, callback);
}
judgeService.getContestTimeInfo = function(p0, callback) {
  dwr.engine._execute(judgeService._path, 'judgeService', 'getContestTimeInfo', p0, callback);
}
judgeService.getResult = function(p0, callback) {
  dwr.engine._execute(judgeService._path, 'judgeService', 'getResult', p0, callback);
}
