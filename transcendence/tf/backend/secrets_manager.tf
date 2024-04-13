#######################
### Intra Client Id ###
#######################

resource "aws_secretsmanager_secret" "intra_client_id" {
  name = "intra-client-id"
}

resource "aws_secretsmanager_secret_version" "intra_client_id" {
  secret_id     = aws_secretsmanager_secret.intra_client_id.id
  secret_string = var.intra_client_id
}

###########################
### Intra Client Secret ###
###########################

resource "aws_secretsmanager_secret" "intra_client_secret" {
  name = "intra-client-secret"
}

resource "aws_secretsmanager_secret_version" "intra_client_secret" {
  secret_id     = aws_secretsmanager_secret.intra_client_secret.id
  secret_string = var.intra_client_secret
}

########################
### Google Client Id ###
########################

resource "aws_secretsmanager_secret" "google_client_id" {
  name = "google-client-id"
}

resource "aws_secretsmanager_secret_version" "google_client_id" {
  secret_id     = aws_secretsmanager_secret.google_client_id.id
  secret_string = var.google_client_id
}

############################
### Google Client Secret ###
############################

resource "aws_secretsmanager_secret" "google_client_secret" {
  name = "google-client-secret"
}

resource "aws_secretsmanager_secret_version" "google_client_secret" {
  secret_id     = aws_secretsmanager_secret.google_client_secret.id
  secret_string = var.google_client_secret
}

#########################
### JWT Access Secret ###
#########################

resource "random_password" "jwt_access_secret" {
  length           = 32
  special          = false
  override_special = "!#$%&*()-_=+[]{}<>:?"
}

resource "aws_secretsmanager_secret" "jwt_access_secret" {
  name = "jwt-access-secret"
}

resource "aws_secretsmanager_secret_version" "jwt_access_secret" {
  secret_id     = aws_secretsmanager_secret.jwt_access_secret.id
  secret_string = random_password.jwt_access_secret.result
}

##########################
### JWT Refresh Secret ###
##########################

data "aws_secretsmanager_random_password" "jwt_refresh_secret" {
  password_length     = 32
  exclude_punctuation = true
}

resource "random_password" "jwt_refresh_secret" {
  length           = 32
  special          = false
  override_special = "!#$%&*()-_=+[]{}<>:?"
}

resource "aws_secretsmanager_secret" "jwt_refresh_secret" {
  name = "jwt-refresh-secret"
}

resource "aws_secretsmanager_secret_version" "jwt_refresh_secret" {
  secret_id     = aws_secretsmanager_secret.jwt_refresh_secret.id
  secret_string = random_password.jwt_refresh_secret.result
}
