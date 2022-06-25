import httplib2

conn = httplib2.HTTPConnectionWithTimeout('http://challenge-36d767a00a1c969c.sandbox.ctfhub.com:10800')

res = conn.request('CTFHUB', '/index.php')

print(res)