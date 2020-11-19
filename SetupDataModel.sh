#!/bin/bash


if [ $HK_ASTROANALYSIS_DIR == "" ] || [ -z $HK_ASTROANALYSIS_DIR ]; then
	echo "HK_ASTROANALYSIS_DIR is not defined or doesn't exist ($HK_ASTROANALYSIS_DIR). Will use lite DataModel."
	ln -s ./leaf/DataModel-lite ./leaf/DataModelDataModel
else 
	echo "HK_ASTROANALYSIS_DIR was found to be: $HK_ASTROANALYSIS_DIR its DataModel will be used"
	ln -s $HK_ASTROANALYSIS_DIR/DataModel ./leaf/DataModel
fi
	

