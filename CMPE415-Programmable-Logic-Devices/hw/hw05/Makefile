# Makefile to help clean and maintain project


.PHONY: clean-proj
clean-proj:
	@find core \( ! -name "*.xise" ! -name "*.ucf" ! -name "*.v" ! -name \
		"*.bit" ! -name "*.log" \) -type f -delete
	@find core -depth -type d -empty -delete
