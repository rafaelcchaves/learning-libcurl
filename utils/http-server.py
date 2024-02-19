# app.py
from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/api/data', methods=['POST'])
def post_data():
    try:
        data = request.get_json()
        # Process the data as needed
        # For now, just echoing back the received data
        return jsonify({"message": "Data received successfully", "data": data})
    except Exception as e:
        return jsonify({"error": str(e)})

if __name__ == '__main__':
    app.run(debug=True)
