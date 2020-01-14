{
  char * ShellName = new char[256];
  ofstream ShellFile(ShellName);
  char * infilename = new char[512];
  char * outfilename = new char[512];
  
  int nevents=1000;
  int neventsPerFile=10;
  for(int nrj=10;nrj<11;nrj++){
  //for(int nrj=3;nrj<16;nrj++){
    //if(nrj == 5 || nrj == 10) continue;
      //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt10pc14374100Hz_e%d_center_nominal_fulltank_0hitstrigger_10000.root",nrj);
      //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt14374100Hz_e%d_center_nominal_fulltank_0hitstrigger_10000.root",nrj);
      //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt10pc14374100Hz_e%d_center_nominal_fulltank_0hitstrigger_10000.root",nrj);
      //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt14374100Hz_4.2kHzBL_e%d_center_nominal_fulltank_0hitstrigger_10000.root",nrj);
      //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt10pc14374100Hz_4.2kHzBL_e%d_center_nominal_fulltank_0hitstrigger_10000.root",nrj);

      sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt1437450Hz_4.2kHzBL_e10_center_nominal_fulltank_0hitstrigger_10000_tmp.root");
    //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt1437450Hz_4.2kHzBL_e%d_center_nominal_fulltank_0hitstrigger_10000.root",nrj);
    //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt1437450Hz_4.2kHzBL_e%d_40PCBLonly_center_nominal_fulltank_0hitstrigger_10000.root",nrj);
    //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt10pc1437450Hz_4.2kHzBL_e%d_center_nominal_fulltank_0hitstrigger_10000.root",nrj);
    
    //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt14374100Hz_40pcblonly_e%d_center_nominal_fulltank_0hitstrigger_10000.root",nrj);
    
    //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt14374100Hz_e%d_center_nominal_fulltank_0hitstrigger_10000.root",nrj);
    //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt14374100Hz_e%d_center_nominal_fulltank_0hitstrigger_nodn_10000.root",nrj);
    //sprintf(infilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt1437450Hz_e%d_center_nominal_fulltank_0hitstrigger_10000.root",nrj);
    
    for(int startBin=0;startBin<nevents;startBin+=neventsPerFile){
      sprintf(ShellName,"../jobs/fitLE_e%d_start%d.sh",nrj,startBin);
      //sprintf(ShellName,"jobs/inputs_e%d_start%d.sh",nrj,startBin);
      //sprintf(outfilename,"/disk01/usr5/bquilain/wcsim_hkhybridmpmt14374100Hz_e%d_center_nominal_fulltank_0hitstrigger_10000.root",nrj);
      sprintf(outfilename,"/disk01/usr5/bquilain/benNano_HKHybrid_20PC_%dMeV_-3and4nsTimeWindow_bin%d_tmp.root",nrj,startBin);
      //sprintf(outfilename,"/disk01/usr5/bquilain/inputs_%dMeV_bin%d.root",nrj,startBin);
      ofstream ShellFile(ShellName);
      if(ShellFile){
	ShellFile<<"#!/bin/bash"<<endl;
	ShellFile<<Form("../app/FitVertexLE -f %s -o %s -s %d -e %d",infilename,outfilename,startBin,startBin+neventsPerFile)<<endl;
	//	ShellFile<<Form("/home/bquilain/nuPRISM/BenjaminAnalysis/FitVertexLE -f %s -o %s -s %d -e %d",infilename,outfilename,startBin,startBin+neventsPerFile)<<endl;
	//ShellFile<<Form("/home/bquilain/nuPRISM/BenjaminAnalysis/AnalyzeWSHierarchy -f %s -o %s -s %d -e %d",infilename,outfilename,startBin,startBin+neventsPerFile)<<endl;
      }
    }
  }
}
