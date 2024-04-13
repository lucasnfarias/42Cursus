import { HttpService } from '@nestjs/axios';
import {
  HttpStatus,
  Inject,
  Injectable,
  UnauthorizedException,
} from '@nestjs/common';
import { ConfigType } from '@nestjs/config';
import { PassportStrategy } from '@nestjs/passport';
import { Strategy, VerifyCallback } from 'passport-oauth2';
import authConfig from '../../config/auth.config';

export type IntraUserProfile = {
  provider: string;
  username: string;
  firstName: string;
  lastName: string;
  email: string;
  avatar: string;
  accessToken?: string;
  refreshToken?: string;
};

@Injectable()
export class FortyTwoOauthStrategy extends PassportStrategy(
  Strategy,
  'forty-two',
) {
  constructor(
    @Inject(authConfig.KEY) authConf: ConfigType<typeof authConfig>,
    private httpService: HttpService,
  ) {
    super({
      authorizationURL: 'https://api.intra.42.fr/oauth/authorize',
      tokenURL: 'https://api.intra.42.fr/oauth/token',
      clientID: authConf.intra.uid,
      clientSecret: authConf.intra.secret,
      callbackURL: authConf.intra.redirect_url,
      proxy: true,
    });
  }

  async validate(
    accessToken: string,
    _refreshToken: string,
    _profile: any,
    done: VerifyCallback,
  ): Promise<any> {
    const user = await this.httpService.axiosRef.get(
      'https://api.intra.42.fr/v2/me',
      {
        params: {
          access_token: accessToken,
        },
      },
    );

    if (user.status != HttpStatus.OK) {
      throw UnauthorizedException;
    }

    const profile: IntraUserProfile = {
      provider: 'forty-two',
      username: user.data.login,
      email: user.data.email,
      firstName: user.data.first_name,
      lastName: user.data.last_name,
      avatar: user.data.image.link,
    };

    done(null, profile);
  }
}
