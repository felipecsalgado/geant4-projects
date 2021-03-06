//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "HistoManager.hh"
#include "G4UnitsTable.hh"
#include "DetectorConstruction.hh"

//Custom
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HistoManager::HistoManager()
    : fFileName("testem3")
{
  Book();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HistoManager::~HistoManager()
{
  delete G4AnalysisManager::Instance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void HistoManager::Book()
{
  // Create or get analysis manager
  // The choice of analysis technology is done via selection of a namespace
  // in HistoManager.hh
  G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetFileName(fFileName);
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetActivation(true); // enable inactivation of histograms

  // Define histograms start values

  const G4String id[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                         "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
                         "20", "21", "22"};
  G4String title;

  // Default values (to be reset via /analysis/h1/set command)
  G4int nbins = 100;
  G4double vmin = 0.;
  G4double vmax = 100.;

  // Create all histograms as inactivated
  // as we have not yet set nbins, vmin, vmax
  for (G4int k = 0; k < kMaxHisto; k++)
  {
    if (k < kMaxAbsor)
      title = "Edep in absorber " + id[k];
    if (k > kMaxAbsor)
      title = "Edep longit. profile (MeV/event) in absorber " + id[k - kMaxAbsor];
    if (k == 2 * kMaxAbsor + 1)
      title = "energy flow (MeV/event)";
    if (k == 2 * kMaxAbsor + 2)
      title = "lateral energy leak (MeV/event)";
    G4int ih = analysisManager->CreateH1(id[k], title, nbins, vmin, vmax);
    analysisManager->SetH1Activation(ih, false);
  }

  // Custom
  G4int ihGamma;
  // Histogram of the input electron particle: 23
  ihGamma = analysisManager->CreateH1("ElectronInput", "Electron Input ", nbins, 0., 300.*MeV);
  analysisManager->SetH1Activation(ihGamma, true);
  G4cout << "Histogram Electron Input id = " << ihGamma << G4endl;
  //
  // Histograms from the particles going out of the material
  // gammas: 24
  ihGamma = analysisManager->CreateH1("gammaOutProfile", "Gamma Energy Profile", nbins, 0., 1.*MeV);
  analysisManager->SetH1Activation(ihGamma, true);
  G4cout << "Histogram Gamma Energy Profile id = " << ihGamma << G4endl;
  // positrons: 25
  ihGamma = analysisManager->CreateH1("positronOutProfile", "Positron Energy Profile", nbins, 0., 1.*MeV);
  analysisManager->SetH1Activation(ihGamma, true);
  G4cout << "Histogram Positron Energy Profile id = " << ihGamma << G4endl;
  // electrons: 26
  ihGamma = analysisManager->CreateH1("electronOutProfile", "Electron Energy Profile", nbins, 0., 1.*MeV);
  analysisManager->SetH1Activation(ihGamma, true);
  G4cout << "Histogram Electron Energy Profile id = " << ihGamma << G4endl;

  // 2D histograms --> need to keep developing
  // 
  ihGamma = analysisManager->CreateH2("gammaPlane0AngDist", "Gamma Angular Distribuiton at Plane0", 
                            50, -0.1, 0.1, 50, -0.1, 0.1);
  analysisManager->SetH2Activation(ihGamma, true);
  G4cout << "Histogram H2 Gamma Profile at Plane0 id = " << ihGamma << G4endl;
}
