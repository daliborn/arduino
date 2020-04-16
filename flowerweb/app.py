from flask import Flask, render_template, request
import flower

app = Flask(__name__)


@app.route('/')
def index():
    read_serial = flower.read()
    return render_template('index.html', landMoisture=read_serial[0], temperature=read_serial[1],
                           airMoisture=read_serial[2])


@app.route('/start')
def start():
    flower.write(request.args.get('seconds'))
    read_serial = flower.read()
    return render_template('index.html', landMoisture=read_serial[0], temperature=read_serial[1],
                           airMoisture=read_serial[2])


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
