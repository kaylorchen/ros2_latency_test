all:
	colcon build --build-base build --install-base install --paths ./ --event-handlers console_direct+
	cp -v build/*.json ./
