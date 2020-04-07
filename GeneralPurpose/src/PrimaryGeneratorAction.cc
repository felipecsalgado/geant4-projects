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
/// \file electromagnetic/TestEm3/src/PrimaryGeneratorAction.cc
/// \brief Implementation of the PrimaryGeneratorAction class
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "PrimaryGeneratorAction.hh"

#include "PrimaryGeneratorMessenger.hh"
#include "DetectorConstruction.hh"
#include "HistoManager.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::PrimaryGeneratorAction(DetectorConstruction *det)
    : G4VUserPrimaryGeneratorAction(),
      fParticleGun(0),
      fDetector(det),
      fRndmBeam(0.),
      fGunMessenger(0)
{
  G4int n_particle = 1;
  fParticleGun = new G4ParticleGun(n_particle);
  SetDefaultKinematic();

  //create a messenger for this class
  fGunMessenger = new PrimaryGeneratorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
  delete fGunMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::SetDefaultKinematic()
{
  G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition *particle = particleTable->FindParticle(particleName = "e-");
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1., 0., 0.));
  fParticleGun->SetParticleEnergy(1. * GeV);
  G4double position = -0.5 * (fDetector->GetWorldSizeX());
  fParticleGun->SetParticlePosition(G4ThreeVector(position, 0. * cm, 0. * cm));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)
{
  //this function is called at the begining of event
  //
  //randomize the beam, if requested.
  if (fRndmBeam > 0.5)
  {
    G4cout << "Custom Primary!!" << G4endl;
    CustomESpec(anEvent);
  }
  else
  {
    //G4cout << "Single Primary!!" << G4endl;
    fParticleGun->GeneratePrimaryVertex(anEvent);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::CustomESpec(G4Event *anEvent)
{
  // Custom
  G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  //
  G4int Ntotal = 2;
  G4double Eenergy[] = {100, 200}; //MeV
  G4int ESpec[] = {10, 5};         //MeV

  for (G4int i = 0; i < Ntotal; i++)
  {
    fParticleGun = new G4ParticleGun(ESpec[i]);

    particleTable = G4ParticleTable::GetParticleTable();

    fParticleGun->SetParticleDefinition(particleTable->FindParticle(particleName = "e-"));
    //
    fParticleGun->SetParticleEnergy(Eenergy[i] * MeV);
    //
    G4double position = -0.5 * (fDetector->GetWorldSizeX());
    fParticleGun->SetParticlePosition(G4ThreeVector(position, 0. * cm, 0. * cm));
    //
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1., 0., 0.));
    //
    fParticleGun->GeneratePrimaryVertex(anEvent);
  }
}